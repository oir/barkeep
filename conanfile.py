import os

from conan import ConanFile
from conan.tools.files import copy, load


class barkeepConan(ConanFile):
    name = "barkeep"
    # No settings/options are necessary, this is header only
    exports_sources = "barkeep/barkeep.h"
    # We can avoid copying the sources to the build folder in the cache
    no_copy_source = True

    def set_version(self):
        # The version is extracted from the header file
        content = load(self, "barkeep/barkeep.h")
        for line in content.splitlines():
            if line.startswith("#define BARKEEP_VERSION"):
                self.version = line.split()[-1].strip('"')
                break

    def package(self):
        # This will also copy the "include" folder
        copy(
            self,
            "barkeep/barkeep.h",
            self.source_folder,
            os.path.join(self.package_folder, "include"),
        )

    def package_info(self):
        # For header-only packages, libdirs and bindirs are not used
        # so it's necessary to set those as empty.
        self.cpp_info.bindirs = []
        self.cpp_info.libdirs = []
