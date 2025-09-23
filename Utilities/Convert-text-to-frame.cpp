#include <iostream>
#include <string>
#include <vector>

int main() {
    // Optimasi I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::vector<std::vector<std::string>> all_blocks;
    std::vector<std::string> current_block;

    // --- LOGIKA PARSING (Sama seperti sebelumnya) ---
    // Baca input baris per baris sampai End-of-File (EOF)
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            // Ketemu baris kosong (delimiter)
            if (!current_block.empty()) {
                all_blocks.push_back(current_block);
                current_block.clear(); // Siapkan untuk blok baru
            }
        } else {
            // Baris berisi data, masukkan ke blok saat ini
            current_block.push_back(line);
        }
    }
    // Tangani blok terakhir jika file tidak diakhiri dgn baris kosong
    if (!current_block.empty()) {
        all_blocks.push_back(current_block);
    }

    // --- LOGIKA OUTPUT BARU (Sesuai permintaan Anda) ---

    bool first_block = true; // Flag untuk mengatur koma separator

    // Iterasi setiap BLOK yang telah kita parse
    for (const auto& block : all_blocks) {
        
        // Tambahkan koma dan spasi SEBELUM blok kedua, ketiga, dst.
        if (first_block) {
            first_block = false;
        } else {
            std::cout << ", ";
        }

        // Cetak pembuka Raw String Literal
        std::cout << "R\"(";

        // Sekarang, cetak semua baris di dalam blok ini.
        // Jika blok ini berisi beberapa baris (misal: "line 1" dan "line 2"),
        // kita akan menggabungkannya dengan karakter newline (\n).
        bool first_line_in_block = true;
        for (const std::string& str_in_block : block) {
            if (first_line_in_block) {
                first_line_in_block = false;
            } else {
                // Tambahkan karakter newline literal di antara baris dalam blok yang sama
                std::cout << "\n";
            }
            for(size_t i = 0; i < str_in_block.size(); i++){
                std::cout << str_in_block[i];
                if(i < str_in_block.size()-1){
                    std::cout << " ";
                }
            }
        }

        // Cetak penutup Raw String Literal
        std::cout << ")\"";
    }

    // Beri newline di akhir output agar terminal rapi
    std::cout << "\n"; 

    return 0;
}