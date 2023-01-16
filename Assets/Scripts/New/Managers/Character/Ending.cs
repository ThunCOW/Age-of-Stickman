using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class Ending : MonoBehaviour
{
    public static Ending Instance;

    public Image BlackScreen;

    public GameObject DemonSummonerEnd;

    public GameObject ThanksForPlayingCanvas;

    public GameObject ReturnToGameOpeningButton;

    void Start()
    {
        Instance = this;    
    }

    public void GameEnd()
    {
        StartCoroutine(End());
    }
    
    private IEnumerator End()
    {
        
        yield return new WaitForSeconds(4);
        
        // Black Screen Opens

        Color black = Color.black;
        black.a = 0;


        float timer = 0;
        float TimeToBlack = 4.5f;
        while(timer < TimeToBlack)
        {
            timer += Time.deltaTime;

            black.a = (timer / TimeToBlack);
            BlackScreen.color = black;

            yield return new WaitForFixedUpdate();
        }

        // Ending screen Made with Unity etc shit

        yield return new WaitForSeconds(10);

        // Set new positions and Screen clears again

        GameObject player = GameManager.Instance.Player.gameObject;
        player.transform.position = new Vector3(0, 50 + player.transform.position.y, 0);

        GameObject summoner = Instantiate(DemonSummonerEnd);
        summoner.transform.position = new Vector3(10, 50 + summoner.transform.position.y, 0);
        summoner.GetComponent<Unit>().unitController.spineSkeletonAnimation.AnimationState.SetAnimation(1, "Demon Magician/idle", true);
        summoner.transform.localScale = new Vector3(-summoner.transform.localScale.x, summoner.transform.localScale.y, summoner.transform.localScale.z);

        GameObject portal = Instantiate(GameManager.Instance.PortalPrefab);
        portal.transform.position = new Vector3(summoner.transform.position.x + 0.93f, summoner.transform.position.y + 0.55f, 0);
        portal.transform.rotation = Quaternion.Euler(0,0,-90);

        Camera.main.orthographicSize = 5;
        Camera.main.GetComponent<SmoothCameraFollow>().enabled = false;

        Camera.main.transform.position = new Vector3((player.transform.position.x + summoner.transform.position.x) / 2, player.transform.position.y + 1.77f, Camera.main.transform.position.z);
        
        timer = 2;
        float TimeToWhite = 2;
        while(timer > 0)
        {
            timer -= Time.deltaTime;

            black.a = (timer / TimeToWhite);
            BlackScreen.color = black;

            yield return new WaitForFixedUpdate();
        }


        // Boss last speech

        TextBoxManager textBoxSpawn = Instantiate(GameManager.Instance.TextBoxPrefab).GetComponent<TextBoxManager>();
        textBoxSpawn.transform.position = new Vector3(summoner.transform.position.x, summoner.transform.position.y + 2f, 0);

        textBoxSpawn.ShowText(summoner.GetComponent<UnitDialogues>().dialogueList[0].Context);

        yield return new WaitUntil(() => textBoxSpawn.IsEnded);

        yield return new WaitForSeconds(0.5f);

        textBoxSpawn = Instantiate(GameManager.Instance.TextBoxPrefab).GetComponent<TextBoxManager>();
        textBoxSpawn.transform.position = new Vector3(summoner.transform.position.x, summoner.transform.position.y + 2f, 0);

        textBoxSpawn.ShowText(summoner.GetComponent<UnitDialogues>().dialogueList[1].Context);

        yield return new WaitUntil(() => textBoxSpawn.IsEnded);

        yield return new WaitForSeconds(0.5f);

        // Boss leaves through portal

        summoner.GetComponent<Unit>().unitController.spineSkeletonAnimation.AnimationState.SetAnimation(1, "Demon Magician/Exit_2", false);
        StartCoroutine(MoveSummonerBeforeEnd(summoner));

        // Close Portal

        yield return new WaitForSeconds(1.7f);

        float countdownToDestroyPortal = 1;
        while (countdownToDestroyPortal > 0)
        {
            countdownToDestroyPortal -= Time.deltaTime;
            float perc = countdownToDestroyPortal / 1;
            portal.transform.localScale = new Vector3(perc, perc, 1);
            yield return new WaitForFixedUpdate();
        }
        Destroy(summoner);
        Destroy(portal);

        // Player Begins to Move Right

        Unit PlayerUnit = player.GetComponent<Unit>();
        PlayerUnit.unitController.spineSkeletonAnimation.AnimationState.SetAnimation(1, PlayerUnit.activeAnimations.Movement.SpineAnimationReference, true);
        StartCoroutine(MovePlayerBeforeEnd(player));

        // Camera begins to move towrads Thanks For Playing canvas

        ThanksForPlayingCanvas.transform.parent = null;

        float countDown = 7f;
        while(countDown > 0)
        {
            countDown -= Time.deltaTime;
            Camera.main.transform.position = new Vector3(Camera.main.transform.position.x, Camera.main.transform.position.y + 0.8f * Time.deltaTime, Camera.main.transform.position.z);
            yield return new WaitForFixedUpdate();
        }

        yield return new WaitForSeconds(3);

        ReturnToGameOpeningButton.SetActive(true);
        TMP_Text returnMenuTextObj = ReturnToGameOpeningButton.transform.GetChild(0).GetComponent<TMP_Text>();
        black = returnMenuTextObj.color;
        while(countDown < 0.75f)
        {
            countDown += Time.deltaTime;

            black.a = countDown / 1.5f;
            returnMenuTextObj.color = black;
            
            yield return new WaitForFixedUpdate();
        }
        // Black Screen Opens

        /*black.a = 0;

        timer = 0;
        TimeToBlack = 4.5f;
        while (timer < TimeToBlack * 0.7f)
        {
            timer += Time.deltaTime;

            black.a = (timer / TimeToBlack);
            BlackScreen.color = black;

            yield return new WaitForFixedUpdate();
        }

        SceneLoader.Instance.FinishGame();*/
    }

    private IEnumerator MoveSummonerBeforeEnd(GameObject summoner)
    {
        while (summoner != null)
        {
            summoner.transform.position = new Vector3(summoner.transform.position.x + 1 * Time.deltaTime, summoner.transform.position.y, summoner.transform.position.z);
            yield return new WaitForFixedUpdate();
        }

        while(true)
        {
            if (summoner == null)
                break;
            summoner.transform.position = new Vector3(summoner.transform.position.x + 1.5f * Time.deltaTime, summoner.transform.position.y, summoner.transform.position.z);
            yield return new WaitForFixedUpdate();
        }
    }

    private IEnumerator MovePlayerBeforeEnd(GameObject player)
    {
        while(true)
        {
            player.transform.position = new Vector3(player.transform.position.x + 2 * Time.deltaTime, player.transform.position.y, player.transform.position.z);
            yield return new WaitForFixedUpdate();
        }
    }
}
