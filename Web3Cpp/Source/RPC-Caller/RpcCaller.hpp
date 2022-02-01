#pragma once
#include "../../Dependencies/json-rpc-cxx/client.hpp"
#include "CppHttpClientConnector.hpp"
#include "../../Dependencies/nlohmann/json.hpp"

/// @brief  Definition for RpcCaller. It defines methods for making RPC calls.
///         It uses the json-rpc-cxx and cpp-http libraries.
class RpcCaller
{
using json = nlohmann::json;
public:
    /// @brief Constructor
    RpcCaller()
        : m_httpClient(m_domain, m_endpoint),
        m_jsonRpcClient(m_httpClient, jsonrpccxx::version::v2) {}
    /// @brief Destructor
    ~RpcCaller() {}

    std::string getBlockNumber() {
        return m_jsonRpcClient.CallMethod<std::string>(JsonRpcId, "eth_blockNumber", {});
    }

    std::string getChainId() {
        return m_jsonRpcClient.CallMethod<std::string>(JsonRpcId, "eth_chainId", {});
    }

    std::string getGasPrice() {
        return m_jsonRpcClient.CallMethod<std::string>(JsonRpcId, "eth_gasPrice", {});
    }

    static constexpr int JsonRpcId = 1;


private:
    /// @brief Domain to call RPCs on
    const std::string m_domain = "https://bsc-dataseed.binance.org";

    /// @brief Endpoint to call RPCs on
    const std::string m_endpoint = "/";

    /// @brief Client for cpp-httplib library
    CppHttpClientConnector m_httpClient;

    /// @brief Client for json-rpc-cxx library
    jsonrpccxx::JsonRpcClient m_jsonRpcClient;
};