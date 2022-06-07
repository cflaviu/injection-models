import qbs

CppApplication {
    consoleApplication: true
    cpp.cxxLanguageVersion: "c++20"
    cpp.enableRtti: false
    cpp.includePaths: ["."]
    install: true
    files: [
        "interface_based_model.hpp",
        "main.cpp",
        "template_based_model.hpp",
    ]
}
