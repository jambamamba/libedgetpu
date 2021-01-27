# generate a .bzl file with variable called TOOLCHAIN_ROOT_DIR=$TOOLCHAIN_ROOT_DIR (rhs is grabbed from bash env)

def _impl(repository_ctx):
  repository_ctx.file("a53_toolchain_root.bzl", "TOOLCHAIN_ROOT_DIR = \"%s\"" % \
    repository_ctx.os.environ.get("TOOLCHAIN_ROOT_DIR", "/home/dev/oosman/.leila/toolchains/arm53sdk"))
  repository_ctx.file("BUILD", "")

a53_toolchain_repository = repository_rule(
    implementation=_impl,
    environ = ["TOOLCHAIN_ROOT_DIR"],
)
