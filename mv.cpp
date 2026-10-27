#include <iostream>
#include <filesystem>
#include <string>
#include <cstdlib>

namespace fs = std::filesystem;
static inline void rename_file(const std::string& old_file, const std::string& new_file) {
    std::error_code ec;
    
    if (fs::is_regular_file(old_file)) {
        fs::rename(old_file, new_file, ec);    
        if (ec) {
            std::cerr << "failed to rename the file: " << ec.message() << "\n";
        }
    } else {
        std::cerr << "input is either not a file or path not found: " << old_file << "\n";
    }
}

static inline void move_file(const std::string& old_file, const std::string& target_dir) {
    if (fs::is_regular_file(old_file)) {
        fs::path src_path(old_file);
        fs::path dest_path = fs::path(target_dir) / src_path.filename();   
        rename_file(old_file, dest_path.string());
    } else  {
        std::cerr << "input is not a regular file: " << old_file << "\n";
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage : mv <input path> <target file>\n"
                 << "Usage : mv <input path> <target dir>\n";
        return EXIT_FAILURE;
    }

    std::string path = argv[1];
    std::string target = argv[2];
    if (!fs::exists(target) || fs::is_regular_file(target)) {
        rename_file(path, target);
    } else if (fs::is_directory(target)) {
        move_file(path, target);
    } else {
        std::cerr << "target destination is invalid.\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

