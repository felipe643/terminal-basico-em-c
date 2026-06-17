#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <X11/Xlib.h>

int main(){
/*	pid_t pid;

	printf("%d \n", getpid());

	for(int i = 0; i < 4; i++){pid = fork();}

	if(pid == 0){
		printf("pid = %d, pai pid = %d \n", getpid(), getppid());
		for(int i = 0; i < 4; i++){wait(NULL);}
	}

	printf("saindo pid = %d\n", getpid());

*/

	Display *dpy;

	Window win;

	XEvent even;

	dpy = XOpenDisplay(NULL);

	if (dpy == NULL) {
        	printf("Nao foi possivel abrir o display.\n");
        	return 1;
	}

	int screen = DefaultScreen(dpy);

	win = XCreateSimpleWindow(dpy, RootWindow(dpy, screen), 100, 150/*posição*/, 800, 800/*largura*/, 2/*borda*/, BlackPixel(dpy, screen), WhitePixel(dpy, screen));

	XStoreName(dpy, win, "Minha Janela");

	XSelectInput(dpy, win, ExposureMask | KeyPressMask);

	XMapWindow(dpy, win);

	while (1) {
        	XNextEvent(dpy, &even);

        	if (even.type == KeyPress) {
            		break;  // fecha ao pressionar uma tecla
        	}
    	}

	XDestroyWindow(dpy, win);
    	XCloseDisplay(dpy);

}
