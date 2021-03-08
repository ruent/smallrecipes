//A Code to read a txt file into a single string
//ref: https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring

//this one is slower than the one below, but more readable
std::ifstream t("file.txt");
std::stringstream buffer;
buffer << t.rdbuf();

//this one is faster, accrodimng to one comment, then the file is larger than 58K?!
std::ifstream t("file.txt");
t.seekg(0, std::ios::end);
size_t size = t.tellg();
std::string buffer(size, ' ');
t.seekg(0);
t.read(&buffer[0], size); 


//above first version can be adapted to read the string with a delimiter
std::ifstream t(curvedata_location);
std::stringstream buffer;
std::string token;

while(std::getline(t, token, '\n')) {  //or  std::getline(t, token, ',')
    std::cout << token << '\n';
}