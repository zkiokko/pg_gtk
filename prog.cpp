#include "gtk/gtk.h"
@import url("./css/style.css");

static void CExit(GtkButton *btn, gpointer data){
    GtkWindow *win =GTK_WINDOW(data);
    gtk_window_destroy(win);
    /*lib =gtk_label_new("ciao");
    gtk_window_set_child(GTK_WINDOW(win), lib);*/
}
static void onclick1(GtkButton *btn, gpointer data){
    const gchar *s;
    gint i=0; 
    s=gtk_button_get_label(btn);
    if(g_strcmp0(s, "Hello")==0){
        gtk_button_set_label(btn,"Hola");
    }
    else
        gtk_button_set_label(btn,"Hello");
}
static void activate(GtkApplication *app, gpointer user_data){
    g_print("hih");
    GtkWidget *win, *btn1 , *btn2, *btn3, *box;
    GtkStyleContext *contest;
    
    win = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(win),"app(alpha) 0.0.3");
    gtk_window_set_default_size(GTK_WINDOW(win),400,300);
    box =gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
    gtk_box_set_homogeneous(GTK_BOX(box), TRUE);
    gtk_window_set_child(GTK_WINDOW(win), box);
    btn1 =gtk_button_new_with_label("Hello");

    contest= gtk_widget_get_style_context("btn1");
    gtk_style_context_add_class(contest,"btn1");

    g_signal_connect(btn1,"clicked",G_CALLBACK(onclick1), NULL);
    btn2 =gtk_button_new_with_label("exit");
    /*gtk_button_size(GTK_BUTTON(btn2),50,50);*/
    gtk_widget_add_css_class(btn2,G"color:red");
    gtk_button_set_has_frame(GTK_BUTTON(btn1),FALSE);
    g_signal_connect(btn2,"clicked",G_CALLBACK(CExit), win);
    btn3 =gtk_button_new_with_label("Hello");
    g_signal_connect(btn3,"clicked",G_CALLBACK(onclick1), NULL);
    gtk_box_append(GTK_BOX(box),btn1);
    gtk_box_append(GTK_BOX(box),btn2);
    gtk_box_append(GTK_BOX(box),btn3);
    
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