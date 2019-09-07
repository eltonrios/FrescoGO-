void Serial_Score (void) {
    u32 ps[2] = {0,0};
    u32 bests[2][2] = { {0,0}, {0,0} };
    u32 p0 = ps[0] + bests[0][0] + bests[0][1];
    u32 p1 = ps[1] + bests[1][0] + bests[1][1];
    u32 avg = (p0 + p1) / 2;
    u32 total = (S.equilibrio ? min(avg, min(p0,p1)*11/10) : avg);
    u32 bruta = ((G.ps[0]/100)+(G.ps[1]/100))/2;
    u32 equ1 = min(((G.ps[0]/100)),((G.ps[1]/100)))*11/10;
    u32 equ2 = min(bruta, equ1);
    u32 equ3 = bruta - equ2;
    float tempo_restante = (S.timeout/1000)-(G.time/1000);
    float fracao_segundo_restante = ((tempo_restante/60)-(int(tempo_restante/60)));
    float tempo_jogo = G.time/1000;
    float fracao_segundo_jogo = ((tempo_jogo/60)-(int(tempo_jogo/60)));    
    
    Serial.println();
    Serial.println(F("-------------------------------------"));
    sprintf_P(STR, PSTR("        %9s"), S.names[0]);
    Serial.print(STR);
    Serial.print(F(" / "));
    sprintf_P(STR, PSTR("%s"), S.names[1]);
    Serial.print(STR);
    Serial.println();
    Serial.println(F("-------------------------------------"));
    
 /*
 //OK – TEMPO TOTAL
    sprintf_P(STR, PSTR("%10S: "), F("Tempo de Jogo........"));
    Serial.print(STR);
    if (G.time > S.timeout) {
         Serial.print(S.timeout/1000/60);
         Serial.println(F(" min"));
    }
    else if ((G.time/1000) > 59) {
        Serial.print(int(G.time/1000/60));
        Serial.print(F(" min e "));
        if ((fracao_segundo_jogo*60)-(int(fracao_segundo_jogo*60)) >= 0,5) {
            Serial.print(int(fracao_segundo_jogo*60)+1);
            Serial.println(F(" seg"));
        } else {
            Serial.print(int(fracao_segundo_jogo*60));
            Serial.println(F(" seg"));
        }
    } 
    else if (G.time == 0) {
        Serial.print(S.timeout/1000/60);
        Serial.println(F(" min"));
        //acrescentar minutos e segundos por segurança
    }
    else {
        Serial.print((G.time/1000));
        Serial.println(F(" seg"));
    }
    */ 
    //OK – TEMPO RESTANTE
    sprintf_P(STR, PSTR("%10S: "), F("Tempo Restante......."));
    Serial.print(STR);
    if (G.time > S.timeout) {
        Serial.println(F("0 min e 0 seg"));
    }
    else if (((S.timeout-G.time)/1000) > 59) {
        Serial.print(int((S.timeout/1000)-(G.time/1000))/60);        
        Serial.print(F(" min e "));
        if ((int(((S.timeout/1000)-(G.time/1000))/60)*60) == S.timeout/1000) {
            Serial.println(F(" 0 seg"));
        }        
        else if ((fracao_segundo_restante*60)-(int(fracao_segundo_restante*60)) >= 0,5) {
            Serial.print(int(fracao_segundo_restante*60)+1);
            Serial.println(F(" seg"));
        } 
        else {
            Serial.print(int(fracao_segundo_restante*60));
            Serial.println(F(" seg"));
        }
    } else {
        Serial.print((S.timeout/1000)-(G.time/1000));
        Serial.println(F(" seg"));
    }
    
    
    //OK – QUANTIDADE QUEDAS
    sprintf_P(STR, PSTR("%10S: "), F("Quantidade Quedas...."));
    Serial.print(STR);
    Serial.println(Falls());
    
    //OK - VELOCIDADE MÉDIA
    sprintf_P(STR, PSTR("Velocidade Média.....: "));
    Serial.print(STR);
    if (G.time > 5000) {
        Serial.print((int)G.pace[0]);
        Serial.println(F(" km/h"));
    } else {
        Serial.println("---");
    }
    
    //OK – QUANTIDADE DE GOLPES
    sprintf_P(STR, PSTR("%10S: "), F("Golpes..............."));
    Serial.print(STR);
    Serial.println(G.hits);
    
    /*
    //OK - PONTUAÇÃO BRUTA 
    Serial.println(F("-------------------------------------"));
    //sprintf_P(STR, PSTR("Pontuação Bruta......:%5ld"), ((G.ps[0]/100)+(G.ps[1]/100))/2);
    sprintf_P(STR, PSTR("%10S: "), F("Pontuação Bruta......"));
    Serial.print(STR);
    Serial.print(((G.ps[0]/100)+(G.ps[1]/100))/2);    
    Serial.println(F(" pts"));
    */

    //OK – EQUILÍBRIO (PTS PERDIDOS)
    sprintf_P(STR, PSTR("Desconto Equilibrio..: "));
    Serial.print(STR);
    Serial.print(equ3);
    Serial.println(F(" pts (-)"));
             
    /*
    //OK – QUEDAS (PTS PERDIDOS)
    sprintf_P(STR, PSTR("Desconto Quedas......: "));    
    Serial.print(STR);
    Serial.print((((bruta - equ3)*(3*Falls())/100)));
    Serial.println(F(" pts (-)"));
    */
    
    //OK – PONTUAÇÃO FINAL
    Serial.println(F("-------------------------------------"));    
    sprintf_P(STR, PSTR("%10S: "), F("PONTUAÇÃO DA DUPLA..."));
    Serial.print(STR);
    Serial.print(G.total);
    Serial.println(F(" pts"));
    
    //OK - PLACAR INDIVIDUAL
    //nova versão Chico
        for (int i=0; i<2; i++) {
        Serial.println();
        Serial.println(F("-----------------------------------------------"));
        Serial.println();

        sprintf_P(STR, PSTR("%10s: "), S.names[i]);
        Serial.print(STR);
        Serial.print(G.ps[i]/100);
        Serial.println(F(" pts"));

        for (int j=0; j<2; j++) {
            int J = (G.lados[i][0].avg1 <= G.lados[i][1].avg1 ? j : 1-j);
            Serial.print( (j==0) ? F(" rev ") : F(" nrm ") );

            Serial.print(F(" [ "));
            for (int k=0; k<HITS_BESTS; k++) {
                if (j==0 && k>=HITS_BESTS/2) {
                    Serial.print(F("   "));
                } else {
                    sprintf_P(STR, PSTR("%2d "), (int)G.bests[i][J][k]);
                    Serial.print(STR);
                }
            }
            Serial.print(F("] => "));
            Serial.print( (j==0) ? G.lados[i][J].avg2 : G.lados[i][J].avg1 );
            Serial.println(F(" kmh"));
        }
    }
    //fim nova versão Chico
    /*Serial.println(F("-------------------------------------"));
    sprintf_P(STR, PSTR("%10S: "), F("Jogador à esquerda..."));
    Serial.print(STR);
    Serial.println(S.names[0]);
    sprintf_P(STR, PSTR("%10S: "), F("Pontuação............"));
    Serial.print(STR);
    Serial.print(G.ps[0]/100);
    Serial.println(F(" pts"));
        //Não mostra se não estiver marcando destrezas
        if (!S.maximas == 0) {
        //jogador 0
        //inicio dos valores
            int sum0 = 0;
            Serial.print(F("Golpes ESQ [ "));
            for (int k=0; k<HITS_BESTS; k++) {
                sum0 += G.bests[0][0][k];
                sprintf_P(STR, PSTR("%2d "), (int)G.bests[0][0][k]);
                Serial.print(STR);
            }
            Serial.println(F("]"));
            //Serial.println();  
        
            int sum1 = 0;
            Serial.print(F("Golpes DIR [ "));
            for (int k=0; k<HITS_BESTS; k++) {
                sum1 += G.bests[0][1][k];
                sprintf_P(STR, PSTR("%2d "), (int)G.bests[0][1][k]);
                Serial.print(STR);
            }
            Serial.println(F("]"));
            //Serial.println();  
        //fim valores segunda linha
     //fim jogador 0
     
        } else {
          //Mostra os golpes mais potentes de direita (quando não estao sendo marcados os backs
            int sum1 = 0;
            Serial.print(F("Maximas [ "));
            for (int k=0; k<HITS_BESTS; k++) {
                sum1 += G.bests[0][1][k];
                sprintf_P(STR, PSTR("%2d "), (int)G.bests[0][1][k]);
                Serial.print(STR);
            }
            Serial.print(F("]"));
            Serial.println();            
          //Fim dos golpes mais fortes de direita            
    }
    //fim condição para marcar destrezas
     
    Serial.println(F("-------------------------------------"));
    sprintf_P(STR, PSTR("%10S: "), F("Jogador à direita...."));
    Serial.print(STR);
    Serial.println(S.names[1]);
    sprintf_P(STR, PSTR("%10S: "), F("Pontuação............"));
    Serial.print(STR);
    Serial.print(G.ps[1]/100);
    Serial.println(F(" pts"));
            //Não mostra se não estiver marcando destrezas
        if (!S.maximas == 0) {
        //jogador 1
        //inicio dos valores
            int sum2 = 0;
            Serial.print(F("Golpes ESQ [ "));
            for (int k=0; k<HITS_BESTS; k++) {
                sum2 += G.bests[1][0][k];
                sprintf_P(STR, PSTR("%2d "), (int)G.bests[1][0][k]);
                Serial.print(STR);
            }
            Serial.println(F("]"));
            //Serial.println();  
        
            int sum3 = 0;
            Serial.print(F("Golpes DIR [ "));
            for (int k=0; k<HITS_BESTS; k++) {
                sum3 += G.bests[1][1][k];
                sprintf_P(STR, PSTR("%2d "), (int)G.bests[1][1][k]);
                Serial.print(STR);
            }
            Serial.println(F("]"));
            //Serial.println();  
        //fim valores segunda linha
    //fim jogador 1  
        } else {
        //Mostra os golpes mais potentes de direita (quando não estao sendo marcados os backs
            int sum3 = 0;
            Serial.print(F("Maximas [ "));
            for (int k=0; k<HITS_BESTS; k++) {
                sum3 += G.bests[1][1][k];
                sprintf_P(STR, PSTR("%2d "), (int)G.bests[1][1][k]);
                Serial.print(STR);
            }
            Serial.print(F("]"));
            Serial.println();
       //Fim dos golpes mais fortes de direita             
    }
    //fim condição para marcar destrezas
    Serial.println(F("-------------------------------------"));
*/     
    //OK – JUIZ
    sprintf_P(STR, PSTR("%10S: "), F("Juiz................."));
    Serial.print(STR);
    Serial.println(S.juiz);
    Serial.println(F("-------------------------------------")); 
    
    sprintf_P(STR, PSTR("(v%d%d%d/%dcm/%ds/max(%d,%d)/equ%d/cont%d/bolas%d/lim%d/sens%d)"),
                MAJOR, MINOR, REVISION,
                S.distancia,
                (int)(S.timeout/1000),
                (int)S.maximas,
                (int)S.reves,
                (int)S.equilibrio,
                (int)CONT_PCT,
                (int)ABORT_FALLS,
                (int)S.limite,
                //(int)S.sensibilidade);
    Serial.println(STR);
    Serial.println(F(" "));
}



void Serial_Log (void) {
    int ball  = 0;
    u32 ps[2] = {0,0};
    for (int i=0 ; i<S.hit ; i++) {
        s8  dt  = S.dts[i];
        u8  kmh = G.kmhs[i];
 
        if (dt == HIT_SERV) {
            ball = ball + 1;
            Serial.print(F("-- Sequencia "));
            sprintf_P(STR, PSTR("%2d"), ball);
            Serial.print(STR);
            Serial.println(F(" ----------------"));
        }
 
        if (dt == HIT_NONE) {
            continue;
        }
 
        Serial.print(F("  "));
        if (i%2 == 0) {
            if (dt < 0) {
                Serial.print(F("! "));
            } else {
                Serial.print(F("  "));
            }
        } else {
            Serial.print(F("          "));
        }
 
        int back2 = (i%2==1 and dt<0);
 
        if (dt == HIT_SERV) {
            Serial.print(F("****"));
        } else {
            sprintf_P(STR, PSTR("%4d"), (dt>0?dt:-dt)*10);
            Serial.print(STR);
            if (back2) {
                Serial.print(F(" !"));
            }
        }
 
        if (i==S.hit-1 || S.dts[i+1]==HIT_NONE || S.dts[i+1]==HIT_SERV) {
            Serial.println();
            Serial.println(F("   -----   -----"));
            sprintf_P(STR, PSTR("   %5ld   %5ld"), ps[0]/100, ps[1]/100);
            Serial.println(STR);
        } else if (dt == HIT_SERV) {
            // ignore
        } else {
            u16 pt = ((u16)kmh)*((u16)kmh);
            ps[1 - i%2] += pt;
 
            Serial.print(F("  "));
            if (!back2) {
                Serial.print(F("  "));
            }
            if (i%2 == 0) {
                Serial.print(F("        "));
            }
            sprintf_P(STR, PSTR("(%3d / %4d)"), kmh, pt);
            Serial.print(STR);
        }
        Serial.println();
        delay(50);
    }
    
    //Serial.println();
    u32 bests[2][2] = { {0,0}, {0,0} };
    if (S.maximas) {
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                int sum = 0;
                for (int k=0; k<HITS_BESTS; k++) {
                    s8 v = G.bests[i][j][k];
                    if (!S.maximas) {
                        v = POT_VEL;
                    }
                    sum += v;
                }
                int avg = sum / HITS_BESTS;
                bests[i][j] = avg*avg * POT_BONUS * HITS_BESTS;
            }
        }
}
 

    u32 p0 = ps[0] + bests[0][0] + bests[0][1];
    u32 p1 = ps[1] + bests[1][0] + bests[1][1];
 
    Serial.println(F("-------------------------------------"));
    Serial.println();
    Serial.println(F("    Atleta    Vol     Esq     Dir   Total"));
    sprintf_P(STR, PSTR("%10s: %5ld + %5ld + %5ld = %5ld pts"),
        S.names[0], ps[0]/100, bests[0][0]/100, bests[0][1]/100, p0/100);
    Serial.println(STR);
    sprintf_P(STR, PSTR("%10s: %5ld + %5ld + %5ld = %5ld pts"),
        S.names[1], ps[1]/100, bests[1][0]/100, bests[1][1]/100, p1/100);
    Serial.println(STR);
    Serial.println();
    Serial.println(F("-------------------------------------"));
    Serial.println();
 
    u32 avg   = (p0 + p1) / 2;
    u32 total = (S.equilibrio ? min(avg, min(p0,p1)*11/10) : avg);
/*
    sprintf_P(STR, PSTR("MED: %ld | MIN+10%%: %ld | MIN: %ld"),
                    (p0 + p1) / 2 / 100,
                     min(p0,p1)*11 / 1000,
                     total / 100);
    Serial.println(STR);
*/
    Serial.println(F("-------------------------------------"));
    u32 pct = min(990, Falls()*CONT_PCT);
    
    //Pontuação Bruta
    sprintf_P(STR, PSTR("%10S: "), F("Pontuação Bruta......"));
    Serial.print(STR);
    Serial.print(avg/100);
    Serial.println(F(" pts"));
    
    //Equilibrio
    sprintf_P(STR, PSTR("%10S: "), F("Equilibrio..........."));
    Serial.print(STR);
    Serial.print(S.equilibrio ? (avg/100)-(total/100) : 0);    
    Serial.println(F(" pts (-)"));
    
    //Quedas
    sprintf_P(STR, PSTR("%10S: "), F("Quedas..............."));
    Serial.print(STR);
    Serial.print(total*pct/100000);    
    Serial.println(F(" pts (-)"));
    
    //Golpes
    sprintf_P(STR, PSTR("%10S: "), F("Golpes..............."));
    Serial.print(STR);
    Serial.println(G.hits);
    
    //Pontuação Líquida
    sprintf_P(STR, PSTR("%10S: "), F("Pontuação Final......"));
    Serial.print(STR);
    Serial.print(total*(1000-pct)/100000); 
    Serial.println(F(" pts"));       
    Serial.println(F("-------------------------------------"));
    
    //JUIZ
    sprintf_P(STR, PSTR("%10S: "), F("Juiz................."));
    Serial.print(STR);
    Serial.println(S.juiz);
    Serial.println(F("-------------------------------------"));
    
    Serial.print(F("= FrescoGO! (versao "));
    Serial.print(MAJOR);
    Serial.print(".");
    Serial.print(MINOR);
    Serial.print(".");
    Serial.print(REVISION);
    Serial.println(F(") ="));
}
 
int Serial_Check (void) {
    static char CMD[32];
    static int  i = 0;

    char c;
    while (Serial.available()) {
        c = Serial.read();
        if (c=='\n' || c=='\r' || c=='$' ) {
            if (i == 0) {
                                // skip
            } else {
                CMD[i] = '\0';
                goto _COMPLETE;   // complete
            }
        } else {
            CMD[i++] = c;       // continue
        }
    }
    return IN_NONE;
_COMPLETE:
    i = 0;

    if (strncmp_P(CMD, PSTR("modo cel"), 8) == 0) {
        S.modo = MODE_CEL;
    } else if (strncmp_P(CMD, PSTR("modo pc"), 7) == 0) {
        S.modo = MODE_PC;
    } else if (strncmp_P(CMD, PSTR("restaurar"), 9) == 0) {
        return IN_RESET;
    } else if (strncmp_P(CMD, PSTR("reiniciar"), 9) == 0) {
        return IN_RESTART;
    } else if (strncmp_P(CMD, PSTR("terminar"), 8) == 0) {
        return IN_TIMEOUT;
    } else if (strncmp_P(CMD, PSTR("desfazer"), 8) == 0) {
        return IN_UNDO;
    } else if (strncmp_P(CMD, PSTR("placar"), 6) == 0) {
        Serial_Score();
        return IN_NONE;
    } else if (strncmp_P(CMD, PSTR("relatorio"), 9) == 0) {
        Serial_Score();
        Serial_Log();
        return IN_NONE;
    } else if (strncmp_P(CMD, PSTR("tempo "), 6) == 0) {
        S.timeout = ((u32)atoi(&CMD[6])) * 1000;
    } else if (strncmp_P(CMD, PSTR("distancia "), 5) == 0) {
        S.distancia = atoi(&CMD[10]);
    } else if (strncmp_P(CMD, PSTR("maximas sim"), 11) == 0) {
        S.maximas = 1;
    } else if (strncmp_P(CMD, PSTR("maximas nao"), 11) == 0) {
        S.maximas = 0;
    } else if (strncmp_P(CMD, PSTR("equilibrio sim"), 14) == 0) {
        S.equilibrio = 1;
    } else if (strncmp_P(CMD, PSTR("equilibrio nao"), 14) == 0) {
        S.equilibrio = 0;
    } else if (strncmp_P(CMD, PSTR("limite "), 7) == 0) {
        S.limite = atoi(&CMD[7]);
    } else if (strncmp_P(CMD, PSTR("reves "), 5) == 0) {
        S.reves = atoi(&CMD[5]);
        if (S.reves != 0) {
            S.reves = max(REVES_MIN, min(REVES_MAX, S.reves));
        }
/*
    } else if (strncmp_P(CMD, PSTR("continuidade "), 13) == 0) {
        S.continuidade = atoi(&CMD[13]);
*/
    } else if (strncmp_P(CMD, PSTR("esquerda "), 9) == 0) {
        if (strlen(&CMD[9]) < 15) {
            strcpy(S.names[0], &CMD[9]);
        } else {
            goto ERR;
        }
    } else if (strncmp_P(CMD, PSTR("direita "), 8) == 0) {
        if (strlen(&CMD[8]) < 15) {
            strcpy(S.names[1], &CMD[8]);
        } else {
            goto ERR;
        }
    } else if (strncmp_P(CMD, PSTR("juiz "), 5) == 0) {
        if (strlen(&CMD[5]) < 15) {
            strcpy(S.juiz, &CMD[5]);
        } else {
            goto ERR;
        }
    } else {
        goto ERR;
    }

    if (0) {
ERR:;
        Serial.println(F("err"));
OK:;
    } else {
        Serial.println(F("ok"));
    }
    EEPROM_Save();
    PT_All();
    if (S.modo==MODE_CEL) {
        Serial_Score();
    }

    return IN_NONE;
}
