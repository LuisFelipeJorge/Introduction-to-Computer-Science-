## Description

You should receive a list of full names. The names have varying sizes and varying amounts of surnames.

As the number of names to be typed is not initially known, you must read names until you find the character '$', with ASC II decimal value 36.

After reading the names, you should do the following algorithm:

For every even index name in your list (from 0), if the next name exists, you must add * the last name of the current even index name to the next odd index name. At the end, you must print all names, in the same order of entry, skipping a line after each name.
* Add the name to the end of the last surname. No surname should be substituted.
Note: Use dynamic allocation, you do not know how many names will have, the size of each name or how many surnames each name has, so it makes no sense to use static vectors.

### Input example:

```
Bruce Dickinson
John Lennon
Fred Mercury
Augusta Ada Lovelace
Darkness Lalatina$
```
### Output
```
Bruce Dickinson 
John Lennon Dickinson 
Fred Mercury 
Augusta Ada Lovelace Mercury 
Darkness Lalatina 
```