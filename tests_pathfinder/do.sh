
echo test1 no arguments
./pathfinder 2> ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst1.txt ./tests_pathfinder/res/res.txt

echo test2 no file
./pathfinder islands 2> ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst2.txt ./tests_pathfinder/res/res.txt

echo test3 empty file
./pathfinder tests_pathfinder/empty.txt 2> ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst3.txt ./tests_pathfinder/res/res.txt

echo test4 invalid1
./pathfinder tests_pathfinder/invalid1 2> ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst4.txt ./tests_pathfinder/res/res.txt

echo test5 invalid2
./pathfinder tests_pathfinder/invalid2 2> ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst5.txt ./tests_pathfinder/res/res.txt

echo test6 invalid3
./pathfinder tests_pathfinder/invalid3 2> ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst6.txt ./tests_pathfinder/res/res.txt

echo test13 invalid4
./pathfinder tests_pathfinder/invalid4 2> ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst13.txt ./tests_pathfinder/res/res.txt

echo test7 example1
./pathfinder tests_pathfinder/example1 > ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst7.txt ./tests_pathfinder/res/res.txt

echo test8 example2
./pathfinder tests_pathfinder/example2 > ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst8.txt ./tests_pathfinder/res/res.txt

echo test9 easy
./pathfinder tests_pathfinder/easy > ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst9.txt ./tests_pathfinder/res/res.txt

echo test10 medium
./pathfinder tests_pathfinder/medium > ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst10.txt ./tests_pathfinder/res/res.txt

echo test11 hard
./pathfinder tests_pathfinder/hard > ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst11.txt ./tests_pathfinder/res/res.txt

echo test12 hardest
./pathfinder tests_pathfinder/hardest > ./tests_pathfinder/res/res.txt
diff ./tests_pathfinder/res/tst12.txt ./tests_pathfinder/res/res.txt


