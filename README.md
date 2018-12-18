# DV-A
##Shixin Liu, Xingcai Liu, Zeyu Ruan

This is an application about food map for Providence based on Qt with a simple GUI. It can be easily run on Qt Creator rather than to be built on CCV. Just use Qt Creator and open this project. The data is downloaded from YELP but processed and stored in restaurant.csv.

After launching this app, you will see a new window with a search bar on top and a map of Providence on bottom left. You can choose one search mode from name-match(default) and address-match. After typing in search content(e.g. east), click the search button. On the bottom right list will display search results(e.g. East Side Pockets...) with name, address, average stars rated by customers, etc. The match is based on restaurant's name or address and is case insensitive. Also, on the map will display the location of search results. If there's no match, the list will display "No results".

Please note that the path to data file (restaurant.csv) should be adapted before launching this app, which is in dataprocessing.cpp. Since we used local data parsed into program rather than connecting to a database, the data is not so large in scale and won't be updated. Also, all the data is based on YELP and PVD is not a big city, so you may find no results when searching for a restaurant you are familiar with (e.g. Subway...), but the results are all based on the data we parsed.

In future, we will try to improve the GUI to make it mouse sensitive then we can operate more functions. Also the map is currently only a picture which is inconvenient. We will try to use webkit tools on Qt to display Google map online. The data scale can be easily expanded. Then the food map can be used for larger area instead of PVD.


