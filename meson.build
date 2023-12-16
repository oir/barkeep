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

deps = [threads]

subdir('tests')
subdir('python')
