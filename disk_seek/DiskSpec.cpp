#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>


struct DiskSpec {
    int pages_per_track;
    int tracks_per_cylinder;
    int cylinders_per_disk;
    int pages_per_cylinder;
};

// Lookup DASD model (case-insensitive). Returns true if found and fills spec.
bool GetDiskSpec(const std::string& raw_model, DiskSpec& spec) {
    // normalize to lowercase and trim spaces
    std::string model;
    model.reserve(raw_model.size());
    for (char c : raw_model) {
        if (!std::isspace(static_cast<unsigned char>(c)))
            model.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(c))));
    }

    static const std::unordered_map<std::string, DiskSpec> table = {
        {"3380modelk",    {10, 15, 2655, 150}},
        {"3380modele",    {10, 15, 1770, 150}},
        {"3380allothermodels", {10, 15, 885, 150}},
        {"3390-1",        {12, 15, 1113, 180}},
        {"3390-2",        {12, 15, 2226, 180}},
        {"3390-3",        {12, 15, 3339, 180}},
        {"3390-9",        {12, 15, 10017, 180}},
    };

    auto it = table.find(model);
    if (it == table.end()) return false;
    spec = it->second;
    return true;
}