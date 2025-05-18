# Dependencies
gtest = dependency('gtest')
dual_bird_dep = declare_dependency(  # Use the declared dependency from src
  link_with: dual_bird_lib,
  include_directories: inc_dir,
  dependencies: deps
)

# Include directories
inc_dir = include_directories('.', '..')

# Source files for the tests
test_src_files = [
  'src/gtest_main.cc',
  'src/list_utils.cc',
  'src/rsol.t.cc',
  'src/msol.t.cc',
]

# Declare the test executable
tests_dual_bird = executable(
  'tests-dual-bird',
  sources: test_src_files,
  include_directories: inc_dir,
  dependencies: [gtest, dual_bird_dep],
  cpp_args: cppargs,
  install: false
)

# Register the test
test('tests-dual-bird', tests_dual_bird)