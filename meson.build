project('dual-bird', 'cpp',
  version: '0.1.0',
  default_options: ['cpp_std=c++17']
)

# Compiler arguments
cppargs = [
  '-DNG_LOG_USE_STDOUT',
  '-DNGLOG_USE_EXPORT',
  '-DNGLOG_EXPORT=__attribute__((visibility("default")))',
  '-DNGLOG_NO_EXPORT=__attribute__((visibility("hidden")))',
]

# Dependencies
nglog = dependency('ng-log')
deps = [nglog]

# Include subprojects
subdir('src')
subdir('tests')