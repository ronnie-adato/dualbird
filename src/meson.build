# Dependencies
nglog = dependency('ng-log')

deps = [
  nglog,
]

# add definitions
add_project_arguments('-DNG_LOG_USE_STDOUT', language: 'cpp')
add_project_arguments('-DNGLOG_USE_EXPORT', language: 'cpp')
add_project_arguments('-DNGLOG_EXPORT', language: 'cpp')
add_project_arguments('-DNGLOG_NO_EXPORT', language: 'cpp')

# Source files
src_files = [
  'node.cpp',
]

inc_dir = include_directories('.', '..')

args = ['-DNGLOG_EXPORT', '-DNGLOG_NO_EXPORT']

# Main executable
executable('dual-bird',
  sources: ['main.cpp'] + src_files,
  include_directories: inc_dir,
  dependencies: deps,
    cpp_args : args,
  install: true
)

static_library('dual-bird',
  sources: src_files,
  include_directories: inc_dir,
  dependencies: deps,
    cpp_args : args,
  install: true
)