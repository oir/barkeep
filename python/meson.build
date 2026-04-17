pymod = import('python')
installations = {
  '3.11': pymod.find_installation('python3.11', required: false),
  '3.12': pymod.find_installation('python3.12', required: false),
  '3.13': pymod.find_installation('python3.13', required: false),
  '3.14': pymod.find_installation('python3.14', required: false),
}

py_targets = []

foreach ver, py : installations
  if py.found() and py.language_version() == ver # not sure why python3.10 is found as 3.9, etc
    message('Found Python: ' + py.language_version())
    pybind11 = subproject('pybind11').get_variable('pybind11_dep')

    sources = [ 'barkeep.cpp' ]

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

if py_targets.length() > 0
  alias_target('python', py_targets)
endif