pymod = import('python')
installations = {
  '3.9': pymod.find_installation('python3.9', required: false),
  '3.10': pymod.find_installation('python3.10', required: false),
  '3.11': pymod.find_installation('python3.11', required: false),
  '3.12': pymod.find_installation('python3.12', required: false),
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

alias_target('python', py_targets)