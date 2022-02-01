#pragma once
#define CPPHTTPLIB_OPENSSL_SUPPORT
#define OS_WINDOWS // comment this out if not using windows

#include "../../Dependencies/cpp-httplib/httplib.h"
#include "../../Dependencies/json-rpc-cxx/iclientconnector.hpp"
#include "../../Dependencies/json-rpc-cxx/server.hpp"
#include <string>
#include <iostream>

#ifdef OS_WINDOWS
#include <Windows.h>
#include <wincrypt.h>
#endif

/// @brief  Definition for CppHttpClientConnector. Connects the cpp-httplib client.
class CppHttpClientConnector : public jsonrpccxx::IClientConnector
{
public:
    /// @brief Constructor
    /// @param[in] domain domain address to connect to
    /// @param[in] endpoint endpoint to connect to
    explicit CppHttpClientConnector(const std::string& domain, const std::string& endpoint)
        : httpClient(domain.c_str()),
        m_endpoint(endpoint) {}

    /// @brief Posts an RPC request and returns the body of the response
    /// @param[in] request JSON RPC request to send
    std::string Send(const std::string& request) override {
        auto res = httpClient.Post(m_endpoint.c_str(), request, "application/json");
        if (!res || res->status != 200) {
            throw jsonrpccxx::JsonRpcException(-32003, "client connector error, received status != 200");
        }
        return res->body;
    }

private:
    /// @brief cpp-httplib client
    httplib::Client httpClient;

    /// @brief Endpoint to connect to
    const std::string m_endpoint;
};
