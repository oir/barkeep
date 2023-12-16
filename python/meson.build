pymod = import('python')
py39 = pymod.find_installation('python3.9', required: false)
py310 = pymod.find_installation('python3.10', required: false)
py311 = pymod.find_installation('python3.11', required: false)

py_targets = []

foreach py : [ py39, py310, py311 ]
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
    py_targets += tgt
  endif
endforeach

message('Python targets:')
foreach tgt : py_targets
  message('  ' + tgt.name())
endforeach

alias_target('python', py_targets)