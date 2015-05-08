echo '____________________________________________'
echo 
echo '               Starting build'
echo '____________________________________________'
echo
rm -f ./Rifker
g++ -o Rifker Rifki/src/main.cpp -std=c++11
./Rifker