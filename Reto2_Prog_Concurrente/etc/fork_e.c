    if ((p1_pid = fork()) == 0) {
        printf("I am P1 and I am proud of it.");
    }
    else {
        if ((p2_pid = fork()) == 0) {
            p3_pid = fork();
            if (p3_pid == 0) {
                printf("I am P3. I like it.");
            }
            else {
                p4_pid = fork();
                printf("I am P4. Get used to it.")
            }
        }
        else {
            printf("I am the parent process, obey or die!");
        }
    }


