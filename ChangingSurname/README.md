## Description

You should receive a list of full names. The names have varying sizes and varying amounts of surnames.

As the number of names to be typed is not initially known, you must read names until you find the character '$', with ASC II decimal value 36.

After reading the names, you should do the following algorithm:

From the first name on the list, you must change the last name of this name, with the last name of the last name on the list.
Then switch the surnames between the second and penultimate names on the list, and so on.
At the end, you must print all names, in the same order of entry, skipping a line after each name.

Note: Use dynamic allocation, you do not know how many names will have, the size of each name or how many surnames each name has, so it makes no sense to use static vectors.

### Input example:
```
Bruce Dickinson
Samus Aran
John Lennon
Fred Mercury
Augusta Ada Lovelace
Sonya Blade
Darkness Lalatina$
```
### Output
```
Bruce Lalatina
Samus Blade
John Lovelace
Fred Mercury
Augusta Ada Lennon
Sonya Aran
Darkness Dickinson
```