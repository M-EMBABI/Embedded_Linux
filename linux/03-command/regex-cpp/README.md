## Regex Pattern Explanation

The regex pattern `R"(^feature/TN-\d+/[a-zA-Z0-9_-]+$)"` is used to validate branch names in the format `feature/TN-123/branchname`. Below is a breakdown of each component:

- **`R"`**: The `R` indicates a raw string in C++. In a raw string, backslashes are treated as literal characters, which allows for easier reading of regex patterns.

- **`^`**: Asserts the start of the string. This means that whatever follows must appear at the beginning of the string.

- **`feature/`**: Matches the literal string `feature/`, indicating the type of branch.

- **`TN-`**: Matches the literal string `TN-`, which is part of the identifier.

- **`\d+`**: Matches one or more digits. Here, `\d` represents any digit (equivalent to `[0-9]`), and the `+` signifies "one or more occurrences". This part captures the numeric identifier (e.g., `123`).

- **`/`**: Matches the literal `/`, which separates the numeric identifier from the branch name.

- **`[a-zA-Z0-9_-]+`**: This is a character class that matches one or more occurrences of:
    - `a-z`: Any lowercase letter from 'a' to 'z'.
    - `A-Z`: Any uppercase letter from 'A' to 'Z'.
    - `0-9`: Any digit from '0' to '9'.
    - `_`: The underscore character.
    - `-`: The hyphen character.
    
    This part captures the actual name of the branch, allowing alphanumeric characters, underscores, and hyphens.

- **`$`**: Asserts the end of the string. This means that whatever precedes it must be at the end of the string.

In summary, this regex pattern validates that a branch name follows the structure `feature/TN-123/branchname`, ensuring it starts with `feature/`, followed by `TN-`, a numeric identifier, and finally a valid branch name consisting of letters, digits, underscores, or hyphens.
