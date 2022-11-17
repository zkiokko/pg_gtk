#include "gtk/gtk.h"

static void onclick1(GtkButton *btn, gpointer data){
    GtkWidget *lib;
    GtkWindow *win =GTK_WINDOW(data);
    gtk_window_destroy(win);
    /*lib =gtk_label_new("ciao");
    gtk_window_set_child(GTK_WINDOW(win), lib);*/
}
static void activate(GtkApplication *app, gpointer user_data){
    g_print("hih");
    GtkWidget *win, *btn;
    win = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(win),"app(alpha) 0.0.1");
    gtk_window_set_default_size(GTK_WINDOW(win),400,300);
    btn =gtk_button_new_with_label("Click me");
    gtk_window_set_child(GTK_WINDOW(win), btn);
    g_signal_connect(btn,"clicked",G_CALLBACK(onclick1), win);
    gtk_widget_show(win);
}

int main(int argc,char **argv){
    int ret;
    GtkApplication *app;
    app=gtk_application_new("in.aducators",G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK(activate), NULL);
    ret=g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return ret;
}