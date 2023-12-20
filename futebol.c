//questão de futebol da prova 1 substitutiva
Team* init_team(const char * name) {
    
    Team *novo_time = (Team*)malloc(sizeof(Team));
    int tamanho = strlen(name);
    novo_time->name = (char*)malloc((tamanho) + 1);
    strcpy(novo_time->name, name);

    //estatisticas
    novo_time->matches = 0;
    novo_time->my_goals = 0;
    novo_time->othergoals = 0;
    novo_time->points = 0;

    return novo_time;
}

void register_match(Team *team, int my_goals, int othergoals) {
    //Vitória
    if(my_goals > othergoals) {
        team->points += 3;
    }
    //empate
    else if(my_goals == othergoals) {
        team->points += 1;
    }

    team->my_goals += my_goals;
    team->othergoals += othergoals;
}