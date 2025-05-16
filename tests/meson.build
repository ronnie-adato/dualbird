CXX = meson.get_compiler('cpp')

# Dependencies
deps += CXX.find_library('msquic_platform', dirs : ['/usr/local/lib'])


gtest = dependency('gtest')
nglog = dependency('ng-log')

# deps = [gtest, nglog, dualbird]
deps = [gtest, nglog]
deps += CXX.find_library('dual-bird', dirs: meson.current_build_dir() + '/../src')

inc_dir = include_directories('.', '..')

src_files = [
  'src/gtest_main.cc',
  'src/node.t.cc',
]

args = ['-DNGLOG_EXPORT', '-DNGLOG_NO_EXPORT']
tests_dual_bird = executable(
  'tests-dual-bird',
  src_files,
  dependencies : deps,
  include_directories : inc_dir,
  cpp_args : args
)

test('tests-dual-bird', tests_dual_bird)