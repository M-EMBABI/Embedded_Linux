<h2>Regex Pattern Explanation</h2>

<p>The regex pattern <code>R"(^feature/TN-\d+/[a-zA-Z0-9_-]+$)"</code> is used to validate branch names in the format <code>feature/TN-123/branchname</code>. Below is a breakdown of each component:</p>

<ul>
    <li><code>R"</code>: The <code>R</code> indicates a raw string in C++. In a raw string, backslashes are treated as literal characters, which allows for easier reading of regex patterns.</li>

    <li><code>^</code>: Asserts the start of the string. This means that whatever follows must appear at the beginning of the string.</li>

    <li><code>feature/</code>: Matches the literal string <code>feature/</code>, indicating the type of branch.</li>

    <li><code>TN-</code>: Matches the literal string <code>TN-</code>, which is part of the identifier.</li>

    <li><code>\d+</code>: Matches one or more digits. Here, <code>\d</code> represents any digit (equivalent to <code>[0-9]</code>), and the <code>+</code> signifies "one or more occurrences". This part captures the numeric identifier (e.g., <code>123</code>).</li>

    <li><code>/</code>: Matches the literal <code>/</code>, which separates the numeric identifier from the branch name.</li>

    <li><code>[a-zA-Z0-9_-]+</code>: This is a character class that matches one or more occurrences of:</li>
    <ul>
        <li><code>a-z</code>: Any lowercase letter from 'a' to 'z'.</li>
        <li><code>A-Z</code>: Any uppercase letter from 'A' to 'Z'.</li>
        <li><code>0-9</code>: Any digit from '0' to '9'.</li>
        <li><code>_</code>: The underscore character.</li>
        <li><code>-</code>: The hyphen character.</li>
    </ul>
    <li>This part captures the actual name of the branch, allowing alphanumeric characters, underscores, and hyphens.</li>

    <li><code>$</code>: Asserts the end of the string. This means that whatever precedes it must be at the end of the string.</li>
</ul>

<p>In summary, this regex pattern validates that a branch name follows the structure <code>feature/TN-123/branchname</code>, ensuring it starts with <code>feature/</code>, followed by <code>TN-</code>, a numeric identifier, and finally a valid branch name consisting of letters, digits, underscores, or hyphens.</p>
