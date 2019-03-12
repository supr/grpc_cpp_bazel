#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "proto/helloworld.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

class GreeterClient {
	public:
		GreeterClient(std::shared_ptr<Channel> channel)
			:stub_(Greeter::NewStub(channel)) {}

		std::string SayHello(const std::string& user) {
			HelloRequest req;
			req.set_name(user);
			
			HelloReply resp;
			ClientContext ctx;

			Status status = stub_->SayHello(&ctx, req, &resp);
			if(status.ok()) {
				return resp.message();
			} else {
				return "RPC Failed!";
			}
		}

	private:
		std::unique_ptr<Greeter::Stub> stub_;
};

int main(int argc, char** argv) {
	GreeterClient greeter(
			grpc::CreateChannel("0.0.0.0:50051", grpc::InsecureChannelCredentials()));
	std::string user;
	if(argc > 1) {
		user = argv[1];
	} else {
		user = "world";
	}
	std::string reply = greeter.SayHello(user);
	std::cout << "Greeter Client recieved: " << reply << std::endl;
	return 0;
}
