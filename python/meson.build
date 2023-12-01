pymod = import('python')
py = pymod.find_installation('python3.9', required: false)

if py.found()
  pybind11 = subproject('pybind11').get_variable('pybind11_dep')

  sources = [
    'barkeep.cpp',
  ]

  py.install_sources(
    subdir: '../barkeep',
    pure: false,
  )

  tgt = py.extension_module('barkeep',
                            sources : sources,
                            include_directories : incdir,
                            dependencies : deps + [pybind11],
                            install : true)

  message('Python target name: ' + tgt.name())
  alias_target('python', tgt)
endif

