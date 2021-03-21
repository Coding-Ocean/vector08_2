#if 0
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    int kotatuImg = loadImage("assets\\kotatu0.png");
    while (notQuit) {
        clear(220);
    }
}

#else
//�g�p�摜�ւ̃����N
//http://illust-hp.com/img/nekotatu.html

#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    //�摜�ǂݍ���
    int backImg = loadImage("assets\\back.png");
    int kotatuImg = loadImage("assets\\kotatu0.png");
    int kotatuColorImg = loadImage("assets\\kotatu1.png");
    int mikanImg = loadImage("assets\\mikan.png");
    //�����f�[�^
    int kimg = kotatuImg;
    float kpx = width / 2;
    float kpy = height / 2+250;
    //�݂���f�[�^
    const int totalNum = 15;
    struct MIKAN { float px, py, tx, ty; } m[totalNum];
    for (int i = 0; i < totalNum; i++) {
        m[i].tx = kpx - 176;
        m[i].ty = kpy - 42 - 50 * i;
    }
    int curNum = 0;
    float speed = 20;
    int last = totalNum - 1;
    //���C�����[�v
    while (notQuit) {
        //�݂��񔭎�
        if (isTrigger(MOUSE_LBUTTON)) {
            if (curNum < totalNum) {
                m[curNum].px = mouseX;
                m[curNum].py = mouseY;
                curNum++;
            }
        }
        //���Z�b�g
        if (isTrigger(MOUSE_RBUTTON)) {
            curNum = 0;
            m[last].px = 0;
        }
        //�݂���ړ�
        for (int i = 0; i < curNum; i++) {
            float vx = m[i].tx - m[i].px;
            float vy = m[i].ty - m[i].py;
            float mag = sqrt(vx * vx + vy * vy);
            m[i].px = mag > speed ? (m[i].px + vx / mag * speed) : m[i].tx;
            m[i].py = mag > speed ? (m[i].py + vy / mag * speed) : m[i].ty;
        }
        //�����摜�؂�ւ�
        if (m[last].px == m[last].tx) {
            kimg = kotatuColorImg;
        }
        else {
            kimg = kotatuImg;
        }
        //��ʃN���A
        clear(220);
        rectMode(CENTER);
        //�w�i�`��
        if (m[last].px == m[last].tx) {
            image(backImg, kpx, height / 2);
        }
        //�����`��
        image(kimg, kpx, kpy);
        //�݂���`��
        for (int i = 0; i < curNum; i++) {
            image(mikanImg, m[i].px, m[i].py);
        }
    }
}
#endif