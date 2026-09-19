#include <dpp/dpp.h>
#include <fstream>
#include <iostream>

int main() {
    // читаем токен из отдельного файла, не хардкодим в коде
    std::string token;
    std::ifstream file("token.txt");
    std::getline(file, token);

    dpp::cluster bot(token);

    // логирование, чтобы видеть, что происходит
    bot.on_log(dpp::utility::cout_logger());

    // когда бот полностью готов и подключился к Discord
    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(
                dpp::slashcommand("ping", "Проверка, жив ли бот", bot.me.id)
            );
        }
    });

    // обработка вызова slash-команды
    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("pong");
        }
    });

    bot.on_log(dpp::utility::cout_logger());

    bot.start(dpp::st_wait);
}