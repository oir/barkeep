project('barkeep', 'cpp',
        version: run_command('grep', 'BARKEEP_VERSION', 'barkeep/barkeep.h', check : true)
            .stdout().strip().split()[2].strip('"'),
        default_options: [
            'cpp_std=c++20',
            'warning_level=3'
        ]
)

incdir = include_directories(['./'])

threads = dependency('threads')
fmt = subproject('fmt').get_variable('fmt_dep')

deps = [threads, fmt]

subdir('tests')
subdir('python')

barkeep_dep = declare_dependency(
    include_directories : include_directories('./')
)
