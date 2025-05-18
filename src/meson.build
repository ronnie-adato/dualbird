# Include directories
inc_dir = include_directories('.', '..')

# Source files for the library
lib_src_files = [
  'node.cpp',
  'rsol.cpp',
  'msol.cpp',
]

# Declare the library
dual_bird_lib = library(
  'dual-bird',
  sources: lib_src_files,
  include_directories: inc_dir,
  dependencies: deps,
  cpp_args: cppargs,
  install: true
)

# Declare a dependency for the library to be used by tests
dual_bird_dep = declare_dependency(
  link_with: dual_bird_lib,
  include_directories: inc_dir,
  dependencies: deps,
  compile_args: cppargs
)