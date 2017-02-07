#include <stdio.h>
#include <string.h>

static int re_current(char *pattern, char *string);
static int re_wildcard(char *pattern, char *string);

static int
re_wildcard(char *pattern, char *string)
{
	while (*string != '\0') {
		if (re_current(pattern, string)) {
			return 1;
		}
		string++;
	}

	return 0;
}

static int
re_current(char *pattern, char *string)
{
    if (pattern[0] == '\0' && string[0] == '\0') {
        return 1;
    }

    if (pattern[0] == '*' && pattern[1] == '\0') {
        return 1;
    }

    if (pattern[0] == '*') {
        return re_wildcard(pattern + 1, string);
    }

    if (pattern[0] == string[0])
        return re_current(pattern + 1, string + 1);

    return 0;
}

int
re_match(char *pattern, char *string)
{
    while (*string != '\0') {
		if (re_current(pattern, string)) {
            return 1;
        }
        string++;
	}

	return 0;
}
