project('meanwhile', 'cpp', default_options : ['cpp_std=c++20', 'warning_level=3'])

incdir = include_directories(['./', './extern/'])

threads = dependency('threads')

deps = [threads]

sources = [
  'demo.cpp',
  'test.cpp',
]

tests = []

foreach src : sources
  exec_name = src.replace('.cpp', '.out')
  exe = executable(exec_name,
                   src,
                   include_directories : incdir,
                   dependencies : deps)
  tests += [exe]
  test(exec_name, exe)
endforeach

subdir('python')
