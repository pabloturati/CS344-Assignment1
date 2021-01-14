# CS344-Assignment1
CS344-Assignment1 Movie List reader in C
Author: Pablo Turati - turatip@oregonstate.edu
Licence: MIT. 
Refer to `LICENSE` for details.

## Project Description

Application that reads data from a CSV file, provides user with the following functionality:

1. Movies release in the specified year.
2. Highest rated movie for each year.
3. Movies and their year of release for a specific language.

## Compile instructions

### Option 1.  Using compile script

This application includes a bash script to build and deploy the runner (run.sh).  To use it, make sure that run.sh has exection persmissions:

`$ chmod +x run.sh`

Once it is ready, you may execute the compile instructions by running from the project root:

`$ ./run.sh`

This will generate a `movies` exectable file as output.

### Option 2.  Individual commands

Refer to `run.sh` for a detailed command list.

## Run procedure

Once the application runner has been created. Usage is as follow:

`$ ./movies <filename.csv>`

An example where the file name is: `movies_sample_1.csv` would be:
`$ ./movies movies_sample_1.csv`

Where movies_sample_file must be a comma-separated file (.csv)