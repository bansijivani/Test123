#include <vector>
#include <string>

bool ParseCSVResponse(const char* pszLine, std::vector<std::string>& aosRes, char delimiter = ',') {
  if (!pszLine || !*pszLine) {
    // Handle empty or null input string
    return false;
  }

  std::string current_field;
  int nDoubleQuotes = 0;

  while (*pszLine) {
    if (*pszLine == delimiter) {
      // Add previous field to results
      if (!current_field.empty()) {
        aosRes.push_back(current_field);
      }
      current_field.clear();
      nDoubleQuotes = 0;
    } else if (*pszLine == '"') {
      pszLine++;  // Skip opening quote
      if (*pszLine == '"') { // Handle escaped quote (")
        current_field += '"';
        pszLine++;
      } else {
        nDoubleQuotes = (nDoubleQuotes + 1) % 2;  // Toggle quote counting
      }
    } else {
      current_field += *pszLine;
    }
    pszLine++;
  }

  // Add the last field if not empty
  if (!current_field.empty()) {
    aosRes.push_back(current_field);
  }

  return true;
}
