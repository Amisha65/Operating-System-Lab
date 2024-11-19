#shebang.constract
create()
{
    echo "Enter the filename which you want to create: "
    read db;
    if [ -e $db ]
    then
        echo "File already exits, create new database"
    else
        touch $db
        echo "File created"
    fi
}

insert()
{
    if [ -z $db ]
    then
        echo "Database doesnt exist.Create new database"
    else
        echo "Enter the number of record to add: "
        read no

        while [ $no -gt 0 ]
        do
            echo "Enter the roll no.: "
            read rno
            srno=` grep "^$rno" "$db" `
            if [ -z $srno ]
            then
                echo "Enter the name: "
                read name
                echo "Sub1"
                read sub1
                echo "Sub2"
                read sub2
                echo "Sub3"
                read sub3
                avg=$(((sub1+sub2+sub3)/3))
                echo "Average : $avg"

                record=$rno ":" $name ":" $sub1 ":" $sub2 ":" $sub3 ":" $avg
                echo $record >> "$db"
                no=$(($no-1))
            else
                echo "Record already exist"
            fi
        done
    fi
}

search()
{
    echo "Enter the roll no: "
    read rno
    record=`grep "^$rno" "$db" `
    if [ $? -ne 0 ]
    then
        echo "Record not found"
    else
        echo "Record found"
        echo $record
    fi
}

modify()
{
    echo "Enter roll no to modify: "
    read rno
    grep "^$rno" $db > temp1.txt
    grep -v "^$rno" $db > temp2.txt
    mv temp2.txt $db
    if [ $? -ne 0 ]
    then
        echo "Record does not match "
    else
        echo "Enter the data to modify"
        echo "Enter the new name: "
        read name
        echo "New Sub1"
        read sub1
        echo "New Sub2"
        read sub2
        echo "New Sub3"

        read sub3
        avg=$(((sub1+sub2+sub3)/3))
        echo "record Updated "
        record= $rno":"$name":"$sub1":"$sub2":"$sub3":"$avg
        echo "$record"
        echo $record >> "$db"
    fi
}

delete()
{
    echo "Enter roll no to delete there data: "
    read rno
    record=`grep "^$rno" "$db" `
    if [ $? -ne 0 ]
    then
        echo "Record not found"
    else
        echo "Record found"
        echo $record
        record= `grep -v "^$rno" "$db" >temp.txt`
        mv temp.txt $db
        echo "Record deleted"
    fi
}

display()
{
    echo "...Complete Database..."
    cat $db
}

MENU1="***MENU*** \n
1.create \n
2.insert \n
3.search \n
4.modify \n
5.delete \n
6.display \n
7.Exit \n"

while true
do
    echo $MENU1
    echo "Enter the choice"
    read n

    case $n in
        1)create
        ;;
        2)insert
        ;;
        3)search
        ;;
        4)modify
        ;;
        5)delete
        ;;
        6)display
        ;;
        7)exit
        ;;
    esac
done