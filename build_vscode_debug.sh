mkdir build
cd build
# rm -rf *
conan install .. -o use_domain=False -o db=new_full  -o with_tests=True -s build_type=Debug
conan build ..