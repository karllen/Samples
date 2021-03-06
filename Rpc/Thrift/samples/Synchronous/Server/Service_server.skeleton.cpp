// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Service.h"
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PlatformThreadFactory.h>
#include <thrift/concurrency/Thread.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TNonblockingServerSocket.h>
#include <thrift/transport/TNonblockingServerTransport.h>

#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::test::stress;

class ServiceHandler : virtual public ServiceIf {
 public:
  ServiceHandler() {
    // Your initialization goes here
  }

  void echoVoid() {
    // Your implementation goes here
    printf("echoVoid\n");
  }

  int8_t echoByte(const int8_t arg) {
    // Your implementation goes here
    printf("echoByte %c\n", arg);
	return arg;
  }

  int32_t echoI32(const int32_t arg) {
    // Your implementation goes here
    printf("echoI32\n");
	return arg;
  }

  int64_t echoI64(const int64_t arg) {
    // Your implementation goes here
    printf("echoI64\n");
	return arg;
  }

  void echoString(std::string& _return, const std::string& arg) {
    // Your implementation goes here
    printf("echoString\n");
  }

  void echoList(std::vector<int8_t> & _return, const std::vector<int8_t> & arg) {
    // Your implementation goes here
    printf("echoList\n");
  }

  void echoSet(std::set<int8_t> & _return, const std::set<int8_t> & arg) {
    // Your implementation goes here
    printf("echoSet\n");
  }

  void echoMap(std::map<int8_t, int8_t> & _return, const std::map<int8_t, int8_t> & arg) {
    // Your implementation goes here
    printf("echoMap\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  
  /*::apache::thrift::stdcxx::shared_ptr<ServiceHandler> handler(new ServiceHandler());
  ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new ServiceProcessor(handler));
  ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory); 
  server.serve();*/

  stdcxx::shared_ptr<ServiceHandler> handler(new ServiceHandler());
  stdcxx::shared_ptr<TProcessor> processor(new ServiceProcessor(handler));
  stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
  stdcxx::shared_ptr<TNonblockingServerTransport> serverTransport(new TNonblockingServerSocket(port));
  stdcxx::shared_ptr<PlatformThreadFactory> threadFactory = std::shared_ptr<PlatformThreadFactory>(new PlatformThreadFactory());
  stdcxx::shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(10);

  threadManager->threadFactory(threadFactory);
  threadManager->start();

  stdcxx::shared_ptr<TNonblockingServer> server(new TNonblockingServer(processor, protocolFactory, serverTransport, threadManager));

  server->serve();
 
  return 0;
}

