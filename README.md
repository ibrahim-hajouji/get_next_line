<h1 align="center">School 42 get_next_line()</h1>

<div id="header" align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/get_next_linee.png" width="200"/>
</div>


<p align="center">
  The <strong>get_next_line</strong> project teaches how to read from a file descriptor and use static variables in C.
</p>


<h2 align="center">
  <a href="#about">About</a>
  <span> · </span>
  <a href="#usage">Usage</a>
  <span> · </span>
  <a href="#status">Status</a>

<hr>

<h2 id="about">📌 About</h2>
<p>
  The <code>get_next_line</code> function returns a single line from a given file descriptor. If called in a loop, it returns the entire contents of a file line by line, until it reaches the end.
  It must be able to handle any buffer size specified at compilation and manage memory efficiently using <code>static</code> variables.
</p>

<hr>

<h2 id="usage">🚀 Usage</h2>

<p>This function is not a stand-alone program. Its files must be compiled with your own project.</p>

<p><strong>Example main.c:</strong></p>

<pre><code>#include &lt;stdio.h&gt;
#include &lt;fcntl.h&gt;
#include &lt;unistd.h&gt;
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

    (void)argc;
    fd = open(argv[1], O_RDONLY);
    line = "";
    while (line != NULL)
    {
        line = get_next_line(fd);
        printf("%s", line);
    }
    fd = close(fd);
    return (0);
}
</code></pre>

<p><strong>Compile:</strong></p>
<pre><code>gcc main.c get_next_line.c get_next_line_utils.c</code></pre>

<p><strong>Compile with custom BUFFER_SIZE:</strong></p>
<pre><code>gcc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c</code></pre>

<p><strong>Run:</strong></p>
<pre><code>./a.out file.txt</code></pre>

<p><strong>Run with stdin:</strong></p>
<pre><code>./a.out /dev/tty</code></pre>

<p>The program will wait for input, and echo the line read using <code>get_next_line</code>. Exit with <code>ctrl-c</code>.</p>

<hr>

<h2 id="status">📊 Status</h2>
<ul>
  <li>Finished: 2024-01-19</li>
  <li>Grade: 125/100</li>
</ul>

<hr>

