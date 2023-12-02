project('barkeep', 'cpp', default_options : ['cpp_std=c++20', 'warning_level=3'])

incdir = include_directories(['./'])

threads = dependency('threads')

deps = [threads]

subdir('tests')
subdir('python')
