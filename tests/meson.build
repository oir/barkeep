catch = dependency('catch2-with-main', default_options: ['tests=false'])

demos = [
  'demo.cpp',
  'demo-fmtlib.cpp',
  'demo-stdfmt.cpp',
]

test_sources = [
  'test.cpp',
  'test-fmtlib.cpp',
  'test-stdfmt.cpp',
]

tests = []

foreach src : demos
  exec_name = src.replace('.cpp', '.out')
  exe = executable(exec_name,
                   src,
                   include_directories : incdir,
                   dependencies : deps)
  tests += [exe]
  test(exec_name, exe)
endforeach

foreach src : test_sources
  exec_name = src.replace('.cpp', '.out')
  exe = executable(exec_name,
                   src,
                   include_directories : incdir,
                   dependencies : deps + [catch])
  tests += [exe]
  test(exec_name, exe)
endforeach

alias_target('tests', tests)
