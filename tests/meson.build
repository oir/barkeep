catch = subproject('catch2').get_variable('catch2_dep')

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
                   dependencies : deps + [catch])
  tests += [exe]
  test(exec_name, exe)
endforeach

