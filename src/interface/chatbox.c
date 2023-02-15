/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** interface
*/

#include "rpg.h"

void set_chatbox(entity_t *entity, chatbox_t *chatbox, int nb)
{
    chatbox->dialog = entity->dialog[entity->state];
    sfSprite_setTexture(chatbox->pers, chatbox->texture[nb], sfFalse);
    sfText_setString(chatbox->text, chatbox->dialog[0]);
    chatbox->count_dialog = 0;
}

void display_chatbox(csfml_t *csfml)
{
    sfRenderWindow_drawSprite(csfml->var.window,
    csfml->interface.chatbox.chat, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.chatbox.text, NULL);
}

void event_chatbox(csfml_t *csfml)
{
    int k = 0;
    sfEvent ev;
    while (sfRenderWindow_pollEvent(csfml->var.window, &ev)) {
        if ((sfKeyboard_isKeyPressed(sfKeyEnter) ||
        sfKeyboard_isKeyPressed(sfKeySpace)) &&
            !csfml->interface.chatbox.cooldown_input)  {
            csfml->interface.chatbox.cooldown_input = 10;
            csfml->interface.chatbox.count_dialog += 1;
            k = csfml->interface.chatbox.count_dialog;
            if (!csfml->interface.chatbox.dialog[k])
                csfml->interface.menu = 0;
            else {
                k = csfml->interface.chatbox.count_dialog;
                sfText_setString(csfml->interface.chatbox.text,
                csfml->interface.chatbox.dialog[k]);
            }
        }
        if (ev.type == sfEvtClosed) {
            sfRenderWindow_close(csfml->var.window);
            csfml->var.wind = 1;
        }
    }
}

void chatbox(csfml_t *csfml, chatbox_t *chatbox)
{
    sfVector2f vect = sfView_getCenter(csfml->var.view);
    vect.x -= 900.0;
    vect.y += 300.0;
    sfSprite_setPosition(chatbox->chat, vect);
    sfSprite_setPosition(chatbox->pers, vect);
    vect.x += 100.0;
    vect.y += 100.0;
    sfText_setPosition(chatbox->text, vect);
    event_chatbox(csfml);
    display_chatbox(csfml);
    if (csfml->interface.menu != 5) {
        csfml->var.cooldown_menu = 50;
    }
    if (csfml->interface.chatbox.cooldown_input > 0)
        csfml->interface.chatbox.cooldown_input--;
    sfRenderWindow_display(csfml->var.window);
}