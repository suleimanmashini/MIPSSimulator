#c! /bin/mips_testbench
#take command line parameter
echo "...................................."
echo "......__...__..__..______...____...."
echo "...../  |./  |.| |.| __  \./ ___|..."
echo "..../   |/   |.| |.| |_| |.\ \__...."
echo ".../         |.| |.|  ___/..\__ \..."
echo "../  /|   /| |.| |.| |......__| |..."
echo "./__/ |__/ |_|.|_|.|_|.....|____/..."
echo "...................................."

echo "SULEIMAN MASHINI - IONUT MOTOI - VICTOR SANCHEZ"
echo "enter simulator path"
#read path
touch results.csv
echo -e "TestID  ',' Instruction',' Status ',' Author ',' [Message]" >> results.csv
#open test directories
for directory in *
do
    if [ -d "$directory" ]
    then
#initialize ref variables
        binary="./$directory/$directory.mips.bin"
        stdin="./$directory/$directory.stdin"
        ref_stdout=`cat ./$directory/$directory.ref.stdout`

#pipe to program then pipe output to variable

        sam=$(cat $stdin | ./MIPS $binary)

#get exit code
        got_exit_code=$?
#fetch outputs
        ref_exit_code=`cat ./$directory/$directory.ref.retcode`

#test
        echo "test on:" $binary
        echo "ref exit code is:" $ref_exit_code
        echo "exit code is:" $got_exit_code
        if  [ $ref_exit_code -eq $got_exit_code ]
        then
            pass_exit_code=true
            echo "true"
        else
            pass_exit_code=false
            echo "false"
        fi
        if  [ "$sam" == "$ref_stdout" ]
        then
            pass_stdout=true
            echo "true"
        else
            pass_stdout=false
            echo "false"
        fi

        if [[ pass_exit_code  && pass_stdout  ]]
        then
            status=Pass
        else
            status=Fail
        fi

        echo "ref stdout is:" $ref_stdout
        echo "stdout is:" $sam

        echo -e "$directory  ',' // ',' $status ',' Author ',' [Message]" >> results.csv

fi
done



