#include <stdio.h>
#include <pwd.h>
#include <stddef.h>
#include <string.h>
struct passwd *getpwnam(const char *name)
{
    struct passwd *ptr;
    setpwent();
    while((ptr = getpwent()) != NULL)
        if(strcmp(name, ptr->pw_name) == 0)
            break;
    endpwent();
    return ptr;
}
int main()
{
    struct passwd *user;
    user = getpwnam("dunk");
    printf("name = \"%s\" , password = \"%s\", user id = %d, group id = %d\n", 
           user->pw_name, user->pw_passwd, user->pw_uid, user->pw_gid);
    return 0;
}

