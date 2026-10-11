int kill_screen_level(int need)
{
    for (int level = 1; level <= 255; level++)
    {
        unsigned char timer = level * 10 + 40;
        if (timer * 10 < need)
            return level;
    }
    return -1;
}