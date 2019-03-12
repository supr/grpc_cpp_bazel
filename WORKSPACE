load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
		name = "com_github_grpc_grpc",
		urls = ["https://github.com/grpc/grpc/archive/109c570727c3089fef655edcdd0dd02cc5958010.tar.gz"],
		strip_prefix = "grpc-109c570727c3089fef655edcdd0dd02cc5958010",
		sha256 = "ddd5c9c42bc609108c2e9494e9cfa34ea42d0efd0eb4b183db8a4124dabdc1c2",
)
load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()

http_archive(
		name = "bazel_compilation_db",
		urls = ["https://github.com/grailbio/bazel-compilation-database/archive/6a29a5cfbf931711f56e58eeeb64eaf8648c2e94.tar.gz"],
		strip_prefix = "bazel-compilation-database-6a29a5cfbf931711f56e58eeeb64eaf8648c2e94",
)
load("@bazel_compilation_db//:aspects.bzl", "compilation_database")
