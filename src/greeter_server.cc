#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "proto/helloworld.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

class GreeterServiceImpl final : public Greeter::Service {
	Status SayHello(ServerContext* ctx, const HelloRequest* req, HelloReply* reply) override {
		std::string prefix("Hello ");
		reply->set_message(prefix + req->name());
		return Status::OK;
	}
};

void RunServer() {
	std::string server_address("0.0.0.0:50051");
	GreeterServiceImpl service;

	ServerBuilder builder;
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	builder.RegisterService(&service);
	std::unique_ptr<Server> server(builder.BuildAndStart());
	std::cout << "Server listening on: " << server_address << std::endl;
	server->Wait();
}

int main(int argc, char** argv) {
	RunServer();
	return 0;
}
