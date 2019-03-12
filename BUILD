load("@com_github_grpc_grpc//bazel:grpc_build_system.bzl", "grpc_proto_library")

grpc_proto_library(
		name = "helloworld_proto",
		srcs = ["proto/helloworld.proto"],
)

cc_binary(
		name = "greeter_server",
		srcs = ["src/greeter_server.cc"],
		deps = [
				':helloworld_proto',
				'@com_github_grpc_grpc//:grpc++',
		],
)

cc_binary(
		name = "greeter_client",
		srcs = ["src/greeter_client.cc"],
		deps = [
				':helloworld_proto',
				'@com_github_grpc_grpc//:grpc++',
		],
)

load("@bazel_compilation_db//:aspects.bzl", "compilation_database")
compilation_database(
		name = "dev_comp_db",
		targets = [ "greeter_server", "greeter_client" ],
)
