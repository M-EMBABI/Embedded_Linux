<h2>Regex Explanation</h2>

<p><code>r'...'</code>:</p>
<ul>
    <li>The <code>r</code> before the string denotes a raw string. This means that backslashes in the string are treated as literal characters and not as escape characters. For example, <code>\n</code> would be interpreted as a newline character in a normal string, but in a raw string, it is simply two characters: a backslash and an 'n'.</li>
</ul>

<p><code>^</code>:</p>
<ul>
    <li>This symbol asserts the start of a line. It means that whatever follows must be at the beginning of the string.</li>
</ul>

<p><code>\d{1,4}</code>:</p>
<ul>
    <li><code>\d</code> matches any digit (equivalent to <code>[0-9]</code>).</li>
    <li><code>{1,4}</code> means "match between 1 and 4 occurrences of the preceding element". So <code>\d{1,4}</code> matches a number that is between 1 and 4 digits long (like 1, 22, 123, or 1234).</li>
</ul>

<p><code>,</code>:</p>
<ul>
    <li>This is a literal comma. It matches the actual comma character that should appear right after the digits.</li>
</ul>

<p><code>st</code>:</p>
<ul>
    <li>This matches the literal characters <code>st</code>, which in this case is part of the street designation (like "street").</li>
</ul>

<p><code>[a-zA-Z ]+</code>:</p>
<ul>
    <li>This is a character class:</li>
    <ul>
        <li><code>a-z</code> matches any lowercase letter from 'a' to 'z'.</li>
        <li><code>A-Z</code> matches any uppercase letter from 'A' to 'Z'.</li>
        <li>The space character is included to allow for spaces in the street name.</li>
    </ul>
    <li>The <code>+</code> means "match one or more occurrences" of any characters defined in the brackets. This part will match the street name, which can consist of multiple words (e.g., "salah salem").</li>
</ul>

<p><code>-</code>:</p>
<ul>
    <li>This matches a literal hyphen character. It is used to separate the street name from the city name.</li>
</ul>

<p><code>[a-zA-Z]+</code>:</p>
<ul>
    <li>Similar to the previous character class, this matches one or more alphabetic characters (both lowercase and uppercase) without spaces. This part will match the city name (like "Giza").</li>
</ul>

<p><code>$</code>:</p>
<ul>
    <li>This symbol asserts the end of a line. It means that whatever precedes it must be at the end of the string.</li>
</ul>
