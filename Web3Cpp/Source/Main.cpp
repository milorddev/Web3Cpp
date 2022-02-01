
#include "RPC-Caller/RpcCaller.hpp"
//#include "../Dependencies/BigNumber/BigIntegerLibrary.hh"
#include <stdlib.h>
using namespace std;

int main() {
	// instantiate object to call Rpc methods
	RpcCaller rpcCaller;

	// get block number
	auto blockNumberRaw = rpcCaller.getBlockNumber();
	auto blockNumber = strtol(blockNumberRaw.c_str(), NULL, 16);
	cout << "Block number: " << blockNumber << endl;

	// get chain id
	auto chainIdRaw = rpcCaller.getChainId();
	auto chainId = strtol(chainIdRaw.c_str(), NULL, 16);
	cout << "Chain id: " << chainId << endl;

}
