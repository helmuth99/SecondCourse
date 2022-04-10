// Fill out your copyright notice in the Description page of Project Settings.


#include "SBTService_CheckAttackRange.h"
#include <BehaviorTree/BlackboardComponent.h>
#include <AIController.h>

USBTService_CheckAttackRange::USBTService_CheckAttackRange()
{
	MaxRangeToTarget = 2000.f;
}

void USBTService_CheckAttackRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

	if (ensure(BlackboardComp))
	{
		AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("TargetActor"));
		if (TargetActor)
		{
			AAIController* Controller = OwnerComp.GetAIOwner();
			if (ensure(Controller))
			{
				APawn* AIPawn = Controller->GetPawn();
				if (ensure(AIPawn))
				{
					float RangeToTarget = FVector::Distance(TargetActor->GetActorLocation(), AIPawn->GetActorLocation());

					bool bWithinRange = RangeToTarget < MaxRangeToTarget;

					bool bHasLineOfSight = false;
					if (bWithinRange)
					{
						bHasLineOfSight = Controller->LineOfSightTo(TargetActor);
					}

					BlackboardComp->SetValueAsBool(AttackRangeKey.SelectedKeyName, (bWithinRange && bHasLineOfSight));
				}
			}
		}
	}
}
